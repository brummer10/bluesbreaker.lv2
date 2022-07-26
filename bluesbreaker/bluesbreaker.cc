// generated from file '/home/brummer/projecte/guitarix-git/trunk/tools/ampsim/DK/dkbuild/bluesbreaker/bluesbreaker.dsp' by dsp2cc:
// Code generated with Faust 2.41.1 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>

#define FAUSTFLOAT float

using std::signbit;

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

#define always_inline inline __attribute__((__always_inline__))

typedef enum
{
   input0,
   output0,
   bypass,
   GAIN, // , 0.5, 0.0, 1.0, 0.01 
   TONE, // , 0.5, 0.0, 1.0, 0.01 
   VOLUME, // , 0.5, 0.0, 1.0, 0.01 
} PortIndex;

#include "bluesbreaker_clip_table.h"

namespace bluesbreaker {

class Dsp {
private:
	uint32_t fSampleRate;
	double fConst0;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst7;
	double fConst9;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec3[2];
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst15;
	double fConst17;
	double fConst18;
	double fConst19;
	double fRec2[5];
	double fConst21;
	double fConst23;
	double fConst25;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fConst34;
	double fRec1[3];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec4[2];
	double fConst36;
	double fConst37;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec5[2];
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst44;
	double fConst46;
	double fConst47;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst69;
	double fConst70;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst77;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fRec0[5];
	double fConst91;
	double fConst93;
	double fConst95;
	double fConst97;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;


public:
	void connect(uint32_t port,void* data);
	void del_instance(Dsp *p);
	void clear_state_f();
	void init(uint32_t sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	Dsp();
	~Dsp();
};



Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) fRec3[l0] = 0.0;
	for (int l1 = 0; l1 < 5; l1 = l1 + 1) fRec2[l1] = 0.0;
	for (int l2 = 0; l2 < 3; l2 = l2 + 1) fRec1[l2] = 0.0;
	for (int l3 = 0; l3 < 2; l3 = l3 + 1) fRec4[l3] = 0.0;
	for (int l4 = 0; l4 < 2; l4 = l4 + 1) fRec5[l4] = 0.0;
	for (int l5 = 0; l5 < 5; l5 = l5 + 1) fRec0[l5] = 0.0;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	double fConst1 = 4.1027124691305398e-10 * fConst0;
	fConst2 = 1.0 / (fConst0 * (fConst1 + 1.1309157044076601e-06) + 0.000451093300755755);
	fConst3 = 4.2629388777661799e-05 * fConst0;
	fConst4 = 0.0 - fConst3;
	fConst5 = mydsp_faustpower2_f(fConst0);
	double fConst6 = 6.3473067645139402e-15 * fConst5;
	fConst7 = fConst0 * (1.0357941170043301e-06 - fConst6);
	double fConst8 = 2.53892270580558e-19 * fConst0;
	fConst9 = fConst0 * (fConst5 * (-5.2076501066521999e-15 - fConst8) + 1.0008617014236499e-09) + -6.1926572410149804e-23;
	fConst10 = fConst5 * (3.8083840587083698e-19 * fConst5 + -2.0741740080256501e-11) + -9.2889858615224699e-23;
	fConst11 = 2.6017724776934202e-10 * fConst5;
	fConst12 = fConst0 * (fConst6 + -1.0357941170043301e-06);
	fConst13 = fConst0 * (fConst5 * (5.2076501066521999e-15 - fConst8) + -1.0008617014236499e-09) + -6.1926572410149804e-23;
	double fConst14 = 3.1736533822569701e-15 * fConst0;
	fConst15 = fConst0 * (fConst0 * (1.3008862388467101e-10 - fConst14) + -5.1789705850216303e-07);
	double fConst16 = 6.3473067645139404e-20 * fConst0;
	fConst17 = fConst0 * (fConst0 * (fConst0 * (fConst16 + -2.6038250533260999e-15) + 1.0370870040128201e-11) + -5.00430850711826e-10) + -1.5481643102537501e-23;
	fConst18 = fConst0 * (fConst0 * (fConst14 + 1.3008862388467101e-10) + 5.1789705850216303e-07);
	fConst19 = fConst0 * (fConst0 * (fConst0 * (fConst16 + 2.6038250533260999e-15) + 1.0370870040128201e-11) + 5.00430850711826e-10) + -1.5481643102537501e-23;
	double fConst20 = 3.1736135879468902e-15 * fConst0;
	fConst21 = fConst0 * (fConst20 + 1.2993195540595001e-10) + 5.1154313151948696e-07;
	double fConst22 = 6.3472271758937902e-20 * fConst0;
	fConst23 = fConst0 * (fConst0 * (fConst22 + 1.6629244119435501e-13) + 1.0333171256693599e-09) + -2.52736496790542e-20;
	double fConst24 = 6.3472271758937898e-15 * fConst5;
	fConst25 = 1.0230862630389699e-06 - fConst24;
	double fConst26 = 2.5388908703575098e-19 * fConst0;
	fConst27 = fConst5 * (-3.32584882388709e-13 - fConst26) + -5.0547299358108303e-20;
	fConst28 = 3.8083363055362698e-19 * fConst5 + -2.0666342513387199e-09;
	fConst29 = fConst24 + -1.0230862630389699e-06;
	fConst30 = fConst5 * (3.32584882388709e-13 - fConst26) + 5.0547299358108303e-20;
	fConst31 = fConst0 * (1.2993195540595001e-10 - fConst20) + -5.1154313151948696e-07;
	fConst32 = fConst0 * (fConst0 * (fConst22 + -1.6629244119435501e-13) + 1.0333171256693599e-09) + 2.52736496790542e-20;
	fConst33 = 0.00090218660151151001 - 8.2054249382610797e-10 * fConst5;
	fConst34 = fConst0 * (fConst1 + -1.1309157044076601e-06) + 0.000451093300755755;
	double fConst35 = 1.21802889879982e-18 * fConst0;
	fConst36 = fConst5 * (9.1022217634831498e-16 - fConst35) + -3.17836218601556e-12;
	fConst37 = fConst5 * (fConst35 + 3.0768491956162798e-16) + -3.2394385606378301e-16;
	double fConst38 = 1.2180288987998201e-19 * fConst0;
	fConst39 = fConst38 + 3.0463680224238097e-17;
	fConst40 = -1.2957754242551301e-20 - fConst38;
	fConst41 = fConst5 * (9.1327029366756196e-17 - fConst38) + -1.29577542425513e-14;
	fConst42 = fConst5 * (fConst38 + -1.2177775183675199e-16);
	double fConst43 = 3.3130386047355202e-19 * fConst0;
	fConst44 = fConst5 * (-2.8510850865800099e-15 - fConst43) + 1.6880161198870601e-11;
	double fConst45 = 3.3130386047355202e-20 * fConst0;
	fConst46 = fConst5 * (-2.8502559986691702e-16 - fConst45) + 5.6132991378732298e-14;
	fConst47 = fConst5 * (fConst45 + 2.7674300335507798e-16) + -5.1831016970205202e-14;
	double fConst48 = 1.8270433481997301e-18 * fConst5;
	fConst49 = fConst48 + 6.1371883334531803e-13;
	fConst50 = 1.58949531854816e-15 - fConst48;
	fConst51 = 1.82704334819973e-19 * fConst5;
	fConst52 = 6.4788771212756498e-18 - fConst51;
	fConst53 = fConst51 + 6.0926971715848996e-14;
	fConst54 = -2.5915508485102599e-17 - fConst51;
	fConst55 = 4.9695579071032803e-19 * fConst5 + -3.2260999078188901e-12;
	double fConst56 = 4.9695579071032803e-20 * fConst5;
	fConst57 = fConst56 + -3.21183437688743e-13;
	fConst58 = 2.43713380951195e-13 - fConst56;
	fConst59 = fConst5 * (-9.1022217634831498e-16 - fConst35) + 3.17836218601556e-12;
	fConst60 = fConst5 * (fConst35 + -3.0768491956162798e-16) + 3.2394385606378301e-16;
	fConst61 = fConst38 + -3.0463680224238097e-17;
	fConst62 = 1.2957754242551301e-20 - fConst38;
	fConst63 = fConst5 * (-9.1327029366756196e-17 - fConst38) + 1.29577542425513e-14;
	fConst64 = fConst5 * (fConst38 + 1.2177775183675199e-16);
	fConst65 = fConst5 * (2.8510850865800099e-15 - fConst43) + -1.6880161198870601e-11;
	fConst66 = fConst5 * (2.8502559986691702e-16 - fConst45) + -5.6132991378732298e-14;
	fConst67 = fConst5 * (fConst45 + -2.7674300335507798e-16) + 5.1831016970205202e-14;
	double fConst68 = 3.0450722469995602e-19 * fConst0;
	fConst69 = fConst0 * (fConst0 * (fConst68 + 4.5511108817415699e-16) + -3.0685941667265901e-13) + 1.58918109300778e-12;
	fConst70 = fConst0 * (fConst0 * (1.5384245978081399e-16 - fConst68) + -7.94747659274081e-16) + 1.6197192803189099e-16;
	double fConst71 = 3.0450722469995598e-20 * fConst0;
	fConst72 = fConst0 * (1.5231840112119101e-17 - fConst71) + -3.2394385606378299e-18;
	fConst73 = fConst0 * (fConst71 + -6.4788771212756503e-21);
	fConst74 = fConst0 * (fConst0 * (fConst71 + 4.5663514683378098e-17) + -3.0463485857924498e-14) + 6.4788771212756502e-15;
	fConst75 = fConst0 * (fConst0 * (-6.0888875918375899e-17 - fConst71) + 1.29577542425513e-17);
	double fConst76 = 8.2825965118387896e-20 * fConst0;
	fConst77 = fConst0 * (fConst0 * (fConst76 + -1.42554254329e-15) + 1.61304995390944e-12) + -8.4400805994353007e-12;
	double fConst78 = 8.28259651183879e-21 * fConst0;
	fConst79 = fConst0 * (fConst0 * (fConst78 + -1.42512799933459e-16) + 1.60591718844371e-13) + -2.8066495689366099e-14;
	fConst80 = fConst0 * (fConst0 * (1.3837150167753899e-16 - fConst78) + -1.21856690475597e-13) + 2.5915508485102601e-14;
	fConst81 = fConst0 * (fConst0 * (fConst68 + -4.5511108817415699e-16) + -3.0685941667265901e-13) + -1.58918109300778e-12;
	fConst82 = fConst0 * (fConst0 * (-1.5384245978081399e-16 - fConst68) + -7.94747659274081e-16) + -1.6197192803189099e-16;
	fConst83 = fConst0 * (-1.5231840112119101e-17 - fConst71) + -3.2394385606378299e-18;
	fConst84 = fConst0 * (fConst71 + 6.4788771212756503e-21);
	fConst85 = fConst0 * (fConst0 * (fConst71 + -4.5663514683378098e-17) + -3.0463485857924498e-14) + -6.4788771212756502e-15;
	fConst86 = fConst0 * (fConst0 * (6.0888875918375899e-17 - fConst71) + 1.29577542425513e-17);
	fConst87 = fConst0 * (fConst0 * (fConst76 + 1.42554254329e-15) + 1.61304995390944e-12) + 8.4400805994353007e-12;
	fConst88 = fConst0 * (fConst0 * (fConst78 + 1.42512799933459e-16) + 1.60591718844371e-13) + 2.8066495689366099e-14;
	fConst89 = fConst0 * (fConst0 * (-1.3837150167753899e-16 - fConst78) + -1.21856690475597e-13) + -2.5915508485102601e-14;
	double fConst90 = 1.6565193023677601e-20 * fConst0;
	fConst91 = fConst0 * (fConst90 + 2.5188837627180301e-16) + 6.0901444939991095e-14;
	double fConst92 = 6.09014449399911e-20 * fConst0;
	fConst93 = fConst92 + 3.0450722469995601e-17;
	double fConst94 = 6.0901444939991104e-16 * fConst0;
	fConst95 = fConst94 + 1.2957754242551299e-16;
	double fConst96 = 1.2180288987998201e-12 * fConst0;
	fConst97 = fConst96 + 2.59155084851026e-13;
	double fConst98 = 3.3130386047355202e-20 * fConst5;
	fConst99 = 1.2180288987998199e-13 - fConst98;
	fConst100 = fConst98 + -1.2180288987998199e-13;
	fConst101 = fConst0 * (2.5188837627180301e-16 - fConst90) + -6.0901444939991095e-14;
	fConst102 = 3.0450722469995601e-17 - fConst92;
	fConst103 = 1.2957754242551299e-16 - fConst94;
	fConst104 = fConst96 + -2.59155084851026e-13;
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
	double fSlow0 = 0.0070000000000000062 * double(fVslider0);
	double fSlow1 = 0.0070000000000000062 * double(fVslider1);
	double fSlow2 = 0.0070000000000000062 * double(fVslider2);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec3[0] = fSlow0 + 0.99299999999999999 * fRec3[1];
		double fTemp0 = fConst18 + fConst19 * fRec3[0] + 2.49902074166263e-05;
		fRec2[0] = double(input0[i0]) - (fRec2[1] * (fConst7 + fConst9 * fRec3[0] + 9.9960829666505106e-05) + fRec2[2] * ((fConst10 * fRec3[0] + 0.00014994124449975801) - fConst11) + fRec2[3] * (fConst12 + fConst13 * fRec3[0] + 9.9960829666505106e-05) + fRec2[4] * (fConst15 + fConst17 * fRec3[0] + 2.49902074166263e-05)) / fTemp0;
		fRec1[0] = fConst0 * (fRec2[0] * (fConst21 + fConst23 * fRec3[0]) + fRec2[1] * (fConst25 + fConst27 * fRec3[0]) + fConst0 * fRec2[2] * (fConst28 * fRec3[0] + -2.5986391081189898e-10) + fRec2[3] * (fConst29 + fConst30 * fRec3[0]) + fRec2[4] * (fConst31 + fConst32 * fRec3[0])) / fTemp0 - fConst2 * (fConst33 * fRec1[1] + fConst34 * fRec1[2]);
		fRec4[0] = fSlow1 + 0.99299999999999999 * fRec4[1];
		fRec5[0] = fSlow2 + 0.99299999999999999 * fRec5[1];
		double fTemp1 = fRec4[0] * (fConst0 * (fConst81 + fRec4[0] * (fConst82 + fConst0 * fRec5[0] * (fConst83 + fConst84 * fRec5[0])) + fRec5[0] * (fConst85 + fConst86 * fRec5[0])) + -3.2394385606378302e-13) + fConst0 * (fConst87 + fRec5[0] * (fConst88 + fConst89 * fRec5[0])) + 2.0123392338682202e-12;
		fRec0[0] = double(bluesbreaker_clipclip(double(fConst2 * (fConst4 * fRec1[0] + fConst3 * fRec1[2])))) - (fRec0[1] * (fRec4[0] * (fConst0 * (fConst36 + fRec4[0] * (fConst37 + fConst5 * fRec5[0] * (fConst39 + fConst40 * fRec5[0])) + fRec5[0] * (fConst41 + fConst42 * fRec5[0])) + -1.2957754242551301e-12) + fConst0 * (fConst44 + fRec5[0] * (fConst46 + fConst47 * fRec5[0])) + 8.0493569354728693e-12) + fRec0[2] * (fRec4[0] * (fConst5 * (fConst49 + fRec4[0] * (fConst50 + fRec5[0] * (fConst52 + fConst51 * fRec5[0])) + fRec5[0] * (fConst53 + fConst54 * fRec5[0])) + -1.9436631363826999e-12) + fConst5 * (fConst55 + fRec5[0] * (fConst57 + fConst58 * fRec5[0])) + 1.2074035403209301e-11) + fRec0[3] * (fRec4[0] * (fConst0 * (fConst59 + fRec4[0] * (fConst60 + fConst5 * fRec5[0] * (fConst61 + fConst62 * fRec5[0])) + fRec5[0] * (fConst63 + fConst64 * fRec5[0])) + -1.2957754242551301e-12) + fConst0 * (fConst65 + fRec5[0] * (fConst66 + fConst67 * fRec5[0])) + 8.0493569354728693e-12) + fRec0[4] * (fRec4[0] * (fConst0 * (fConst69 + fRec4[0] * (fConst70 + fConst0 * fRec5[0] * (fConst72 + fConst73 * fRec5[0])) + fRec5[0] * (fConst74 + fConst75 * fRec5[0])) + -3.2394385606378302e-13) + fConst0 * (fConst77 + fRec5[0] * (fConst79 + fConst80 * fRec5[0])) + 2.0123392338682202e-12)) / fTemp1;
		double fTemp2 = 5.18310169702052e-13 * fRec5[0];
		double fTemp3 = 1.2180288987998199e-15 * fRec5[0];
		output0[i0] = FAUSTFLOAT(fConst0 * (fRec0[0] * (fConst91 + fConst0 * fRec4[0] * (fConst93 + fConst95 * fRec5[0]) + fConst97 * fRec5[0]) + fRec0[1] * (fConst99 + fTemp2 + fConst5 * fRec4[0] * (0.0 - fTemp3 + -1.2180288987998201e-19)) + fConst0 * fRec0[2] * (fRec4[0] * (0.0 - 2.5915508485102599e-16 * fRec5[0] + -6.0901444939991104e-17) - 2.4360577975996499e-12 * fRec5[0] + -5.0377675254360701e-16) + fRec0[3] * (fConst100 + fConst5 * fRec4[0] * (fTemp3 + 1.2180288987998201e-19) - fTemp2) + fRec0[4] * (fConst101 + fConst0 * fRec4[0] * (fConst102 + fConst103 * fRec5[0]) + fConst104 * fRec5[0])) / fTemp1);
		fRec3[1] = fRec3[0];
		for (int j0 = 4; j0 > 0; j0 = j0 - 1) {
			fRec2[j0] = fRec2[j0 - 1];
		}
		fRec1[2] = fRec1[1];
		fRec1[1] = fRec1[0];
		fRec4[1] = fRec4[0];
		fRec5[1] = fRec5[0];
		for (int j1 = 4; j1 > 0; j1 = j1 - 1) {
			fRec0[j1] = fRec0[j1 - 1];
		}
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case GAIN: 
		fVslider0_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TONE: 
		fVslider1_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fVslider2_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

Dsp *plugin() {
	return new Dsp();
}

void Dsp::del_instance(Dsp *p)
{
	delete p;
}
} // end namespace bluesbreaker
