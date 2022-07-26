
// bluesbreaker_clip_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  1.400000
 // --table_div  1.544672
 // --table_op  1.000000

struct tablebluesbreaker_clip { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tablebluesbreaker_clip_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tablebluesbreaker_clip&() const { return *(tablebluesbreaker_clip*)this; }
};

 static tablebluesbreaker_clip_imp<200> bluesbreaker_clip_table __rt_data = {
	0,-0.833333,142.143,200, {
	0.000000000000,-0.003529176807,-0.011449633766,-0.020569125098,-0.030200236391,
	-0.040102703879,-0.050152954482,-0.060275869426,-0.070421398274,-0.080554249829,
	-0.090648597314,-0.100685061390,-0.110648856200,-0.120528582639,-0.130315406520,
	-0.140002478083,-0.149584509486,-0.159057459511,-0.168418293270,-0.177664795759,
	-0.186795424951,-0.195809194492,-0.204705578967,-0.213484436606,-0.222145945676,
	-0.230690551736,-0.239118923600,-0.247431916367,-0.255630540207,-0.263715933916,
	-0.271689342399,-0.279552097462,-0.287305601353,-0.294951312658,-0.302490734164,
	-0.309925402423,-0.317256878759,-0.324486741516,-0.331616579379,-0.338647985615,
	-0.345582553128,-0.352421870191,-0.359167516804,-0.365821061564,-0.372384059007,
	-0.378858047348,-0.385244546575,-0.391545056855,-0.397761057204,-0.403894004404,
	-0.409945332124,-0.415916450221,-0.421808744207,-0.427623574855,-0.433362277926,
	-0.439026164004,-0.444616518429,-0.450134601306,-0.455581647591,-0.460958867236,
	-0.466267445385,-0.471508542622,-0.476683295253,-0.481792815624,-0.486838192467,
	-0.491820491271,-0.496740754670,-0.501600002845,-0.506399233951,-0.511139424535,
	-0.515821529979,-0.520446484935,-0.525015203774,-0.529528581027,-0.533987491833,
	-0.538392792385,-0.542745320367,-0.547045895394,-0.551295319449,-0.555494377307,
	-0.559643836962,-0.563744450041,-0.567796952214,-0.571802063599,-0.575760489156,
	-0.579672919073,-0.583540029149,-0.587362481163,-0.591140923237,-0.594875990192,
	-0.598568303896,-0.602218473600,-0.605827096269,-0.609394756906,-0.612922028859,
	-0.616409474135,-0.619857643691,-0.623267077724,-0.626638305958,-0.629971847909,
	-0.633268213160,-0.636527901614,-0.639751403746,-0.642939200852,-0.646091765279,
	-0.649209560662,-0.652293042145,-0.655342656598,-0.658358842829,-0.661342031788,
	-0.664292646767,-0.667211103591,-0.670097810807,-0.672953169864,-0.675777575290,
	-0.678571414863,-0.681335069777,-0.684068914800,-0.686773318436,-0.689448643070,
	-0.692095245119,-0.694713475172,-0.697303678129,-0.699866193337,-0.702401354716,
	-0.704909490887,-0.707390925297,-0.709845976332,-0.712274957439,-0.714678177231,
	-0.717055939599,-0.719408543820,-0.721736284652,-0.724039452438,-0.726318333204,
	-0.728573208745,-0.730804356726,-0.733012050759,-0.735196560497,-0.737358151713,
	-0.739497086382,-0.741613622759,-0.743708015455,-0.745780515509,-0.747831370466,
	-0.749860824438,-0.751869118180,-0.753856489151,-0.755823171580,-0.757769396528,
	-0.759695391949,-0.761601382749,-0.763487590843,-0.765354235211,-0.767201531953,
	-0.769029694341,-0.770838932872,-0.772629455316,-0.774401466766,-0.776155169687,
	-0.777890763961,-0.779608446931,-0.781308413447,-0.782990855908,-0.784655964305,
	-0.786303926258,-0.787934927063,-0.789549149723,-0.791146774991,-0.792727981405,
	-0.794292945323,-0.795841840961,-0.797374840426,-0.798892113749,-0.800393828918,
	-0.801880151910,-0.803351246723,-0.804807275407,-0.806248398091,-0.807674773016,
	-0.809086556560,-0.810483903270,-0.811866965886,-0.813235895367,-0.814590840921,
	-0.815931950028,-0.817259368465,-0.818573240333,-0.819873708075,-0.821160912509,
	-0.822434992841,-0.823696086694,-0.824944330130,-0.826179857669,-0.827402802308,
	-0.828613295551,-0.829811467420,-0.830997446478,-0.832171359852,-0.833333333248
	}
};

double always_inline bluesbreaker_clipclip(double x) {
    double f = fabs(x);
    f = f * bluesbreaker_clip_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = bluesbreaker_clip_table.data[0];
    } else if (i >= bluesbreaker_clip_table.size-1) {
        f = bluesbreaker_clip_table.data[bluesbreaker_clip_table.size-1];
    } else {
    f -= i;
    f = bluesbreaker_clip_table.data[i]*(1-f) + bluesbreaker_clip_table.data[i+1]*f;
    }
    return copysign(f, x);
}

