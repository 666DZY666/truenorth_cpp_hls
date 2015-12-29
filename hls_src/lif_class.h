#ifndef LIF_CLASS_H_
#define LIF_CLASS_H_

#include <cmath>
#include <ap_int.h>

using namespace std;
#define TESTS_NUM 			100
#define CONNECTIONS_MAX 	(16)

#define W_IN    1
#define W_RM    2
#define W_OUT   24
typedef ap_uint<W_IN> lif_in_t;
typedef ap_uint<CONNECTIONS_MAX> lif_in_vec_t;
typedef ap_int<W_OUT> lif_out_t;
typedef ap_int<W_RM> lif_rm_t;

#define SPIKE		 1
#define NOTSPIKE	 0

enum reset_mode{
	normal=0,
	linear=1,
	non_reset=2
};

enum neg_threshold{
	reset=0,
	saturate=1
};
// Create a unique namespace which can help avoid name clashes
namespace neurons {

template<class TI, class TO, class TR, int SZ>
class lif_neuron {
//private:
public:
   const TO alpha_;
   const TO beta_;
   const TO reset_v_;
   const TO lambda_;
   TO weights_[CONNECTIONS_MAX];
   TI* inputs_[CONNECTIONS_MAX];
   TO v_j_;
   TI spike_;
   TI neg_threshold_;
   TR reset_mode_;

//public:
   lif_neuron(TO alpha, TO beta, TO reset_v, TO lambda, TO v_j) :
	    alpha_(alpha), beta_(beta), reset_v_(reset_v), lambda_(lambda), v_j_(v_j) {

   };
   lif_neuron() :
	    alpha_(0), beta_(0), reset_v_(0), lambda_(0), v_j_(0) {};

   //perform leaky-integrate-and-fire computation
   void compute(TI *indata, TO *result, TI *spike);

   // Get methods for polling class instance info - if not used, no hardware
   // will be created for them
   int get_v_j(void) { return v_j_; };
};

template<class TO, int SZ>
void init_weights(TO *weights)
{
#pragma HLS UNROLL
   for (int i = 0; i < SZ; i++) {
	  //TODO: how to initialize the weights
      weights[i] = 1<<i;
   }
}

template<class TO>
void initialize_weights(TO *weights, const TO *values)
{
   for (int i = 0; i < CONNECTIONS_MAX; i++) {
      weights[i] = values[i];
   }
}

template<class TI, class TO, class TR, int SZ>
void lif_neuron<TI,TO,TR,SZ>::compute(TI *indata, TO *result, TI *spike)
{
//#pragma HLS PIPELINE
   TO results[SZ];
   // To ensure coeff_tab is implemented as a ROM on the FPGA, it must
   // be initialized by a separate function. No hardware is synthesized
   // for ROM initialization.
//   init_weights<TO,SZ>(weights);

lif_compute_mul_loop:
   for (unsigned i = 0; i < SZ; i++) {
	   results[i] = indata[i] * weights_[i];
   }
lif_compute_sum_loop:
	//synaptic integration
   for (unsigned i = 0; i < SZ; i++) {
	   this->v_j_ += results[i];
   }
   //leak integration
   this->v_j_ += this->lambda_;

lif_reset_cond:
   if (this->v_j_ >= this->alpha_){
	   if(reset_mode_ == normal){
		   this->v_j_ = this->reset_v_;
	   } else if(reset_mode_ == linear){
		   this->v_j_ = this->reset_v_ - this->alpha_;
	   }
	   this->spike_ = SPIKE;
   }
   else if(this->v_j_ <  this->beta_ ){
	   	if(neg_threshold_){
	   		this->v_j_ = this->beta_;
	   	} else{
   		if(reset_mode_ == normal){
   			this->v_j_ = - this->reset_v_ ;
   		}else if(reset_mode_ == linear){
   			this->v_j_ =  this->v_j_ + this->beta_;
   		}
	   	}
   		this->spike_ = NOTSPIKE;
   	}
   else {
	   this->spike_ = NOTSPIKE;
   }
   *spike  = this->spike_;
   *result = this->v_j_;
}

}; // namespace neurons
#endif // LIF_CLASS_H_
