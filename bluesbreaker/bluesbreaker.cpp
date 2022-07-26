
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include <lv2.h>

///////////////////////// MACRO SUPPORT ////////////////////////////////

#define PLUGIN_URI "urn:brummer:bluesbreaker"

using std::min;
using std::max;

#define __rt_data __attribute__((section(".rt.data")))
#include "bluesbreaker.cc"

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace bluesbreaker {

class Xbluesbreaker
{
private:
    float* input0;
    float* output0;
    float* bypass;
    float bypass_;
    // bypass ramping
    bool needs_ramp_down;
    bool needs_ramp_up;
    float ramp_down;
    float ramp_up;
    float ramp_up_step;
    float ramp_down_step;
    bool bypassed;

    bluesbreaker::Dsp* plugin;

    // private functions
    inline void run_dsp_(uint32_t n_samples);
    inline void connect_(uint32_t port,void* data);
    inline void init_dsp_(uint32_t rate);
    inline void connect_all__ports(uint32_t port, void* data);
    inline void activate_f();
    inline void clean_up();
    inline void deactivate_f();
public:
    // LV2 Descriptor
    static const LV2_Descriptor descriptor;
    // static wrapper to private functions
    static void deactivate(LV2_Handle instance);
    static void cleanup(LV2_Handle instance);
    static void run(LV2_Handle instance, uint32_t n_samples);
    static void activate(LV2_Handle instance);
    static void connect_port(LV2_Handle instance, uint32_t port, void* data);
    static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
    Xbluesbreaker();
    ~Xbluesbreaker();
};

// constructor
Xbluesbreaker::Xbluesbreaker() :

    input0(NULL),
    output0(NULL),
    bypass(NULL),
    bypass_(2),
    needs_ramp_down(false),
    needs_ramp_up(false),
    bypassed(false),
    plugin(bluesbreaker::plugin()) {};

// destructor
Xbluesbreaker::~Xbluesbreaker() {
    plugin->del_instance(plugin);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Xbluesbreaker::init_dsp_(uint32_t rate)
{
    plugin->init(rate);
    // set values for internal ramping
    ramp_down_step = 32 * (256 * rate) / 48000; 
    ramp_up_step = ramp_down_step;
    ramp_down = ramp_down_step;
    ramp_up = 0.0;
}

// connect the Ports used by the plug-in class
void Xbluesbreaker::connect_(uint32_t port,void* data)
{
    switch ((PortIndex)port)
    {
        case 0:
            input0 = static_cast<float*>(data);
            break;
        case 1:
            output0 = static_cast<float*>(data);
            break;
        case 2:
            bypass = static_cast<float*>(data);
            break;
        default:
            break;
    }
}

void Xbluesbreaker::activate_f()
{
    // allocate the internal DSP mem
}

void Xbluesbreaker::clean_up()
{
    // delete the internal DSP mem
}

void Xbluesbreaker::deactivate_f()
{
    // delete the internal DSP mem
}

void Xbluesbreaker::run_dsp_(uint32_t n_samples)
{
    if(n_samples<1) return;

    // get controller values

    // do inplace processing on default
    if(output0 != input0)
        memcpy(output0, input0, n_samples*sizeof(float));

    float buf0[n_samples];
    // check if bypass is pressed
    if (bypass_ != static_cast<uint32_t>(*(bypass))) {
        bypass_ = static_cast<uint32_t>(*(bypass));
        if (!bypass_) {
            needs_ramp_down = true;
            needs_ramp_up = false;
        } else {
            needs_ramp_down = false;
            needs_ramp_up = true;
            bypassed = false;
        }
    }

    if (needs_ramp_down || needs_ramp_up) {
         memcpy(buf0, input0, n_samples*sizeof(float));
    }
    if (!bypassed) {
        plugin->compute(n_samples, output0, output0);
    }
    // check if ramping is needed
    if (needs_ramp_down) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_down >= 0.0) {
                --ramp_down; 
            }
            fade = max(0.0f,ramp_down) /ramp_down_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_down <= 0.0) {
            // when ramped down, clear buffer from dsp
            plugin->clear_state_f();
            needs_ramp_down = false;
            bypassed = true;
            ramp_down = ramp_down_step;
            ramp_up = 0.0;
        } else {
            ramp_up = ramp_down;
        }
    } else if (needs_ramp_up) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_up < ramp_up_step) {
                ++ramp_up ;
            }
            fade = min(ramp_up_step,ramp_up) /ramp_up_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_up >= ramp_up_step) {
            needs_ramp_up = false;
            ramp_up = 0.0;
            ramp_down = ramp_down_step;
        } else {
            ramp_down = ramp_up;
        }
    }
}

void Xbluesbreaker::connect_all__ports(uint32_t port, void* data)
{
    // connect the Ports used by the plug-in class
    connect_(port,data); 
    plugin->connect(port,data);}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Xbluesbreaker::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
    // init the plug-in class
    Xbluesbreaker *self = new Xbluesbreaker();
    if (!self) {
        return NULL;
    }
    self->init_dsp_((uint32_t)rate);
    return (LV2_Handle)self;
}

void Xbluesbreaker::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
    // connect all ports
    static_cast<Xbluesbreaker*>(instance)->connect_all__ports(port, data);
}

void Xbluesbreaker::activate(LV2_Handle instance)
{
    // allocate needed mem
    static_cast<Xbluesbreaker*>(instance)->activate_f();
}

void Xbluesbreaker::run(LV2_Handle instance, uint32_t n_samples)
{
    // run dsp
    static_cast<Xbluesbreaker*>(instance)->run_dsp_(n_samples);
}

void Xbluesbreaker::deactivate(LV2_Handle instance)
{
    // free allocated mem
    static_cast<Xbluesbreaker*>(instance)->deactivate_f();
}

void Xbluesbreaker::cleanup(LV2_Handle instance)
{
    // well, clean up after us
    Xbluesbreaker* self = static_cast<Xbluesbreaker*>(instance);
    self->clean_up();
    delete self;
}

const LV2_Descriptor Xbluesbreaker::descriptor =
{
    PLUGIN_URI ,
    Xbluesbreaker::instantiate,
    Xbluesbreaker::connect_port,
    Xbluesbreaker::activate,
    Xbluesbreaker::run,
    Xbluesbreaker::deactivate,
    Xbluesbreaker::cleanup,
    NULL
};

} // end namespace bluesbreaker

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
    switch (index)
    {
        case 0:
            return &bluesbreaker::Xbluesbreaker::descriptor;
        default:
            return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
