#include <Stdio.h>
#include<math.h>

float sigmoid(float n){
	
	return 1/(1+exp(-n));
}

float input_update(float init_w1, float init_w2, float bias, float x1, float x2){
	
	return (init_w1*x1) + (init_w2*x2) + bias;
}

float hidden_update(float output, int label){
	
	return output*(1-output)*(label-output);
}


float hidden_update2(float new_input, float output, float weight){

	return new_input*output*weight*(1-new_input);
}


int calc(int x1, int x2, int label, float l_r, float w_1_3, float w_1_4, float w_2_3, float w_2_4, float w_3_5, float w_4_5, float bias_3,float bias_4,float bias_5){
	
	float new_input3 = sigmoid(input_update(w_1_3, w_2_3, bias_3, x1, x2));
	float new_input4 = sigmoid(input_update(w_1_4, w_2_4, bias_4, x1, x2));
	float new_input5 = sigmoid(input_update(new_input3, new_input4, bias_5, w_3_5, w_4_5));
	
	float ouput_error = hidden_update(new_input5, label);
	
	float error_4 = hidden_update2(new_input4, ouput_error, w_4_5);
	float error_3 = hidden_update2(new_input3, ouput_error, w_3_5);
	printf("new_input3 :  %g\n\n",new_input3);
	printf("new_input4 :  %g\n\n",new_input4);
	printf("new_input5 :  %g\n\n\n",new_input5);
	
	printf("Error rate node 3 :  %g\n\n",error_3);
	printf("Error rate node 4 :  %g\n\n\n",error_4);

	
	w_3_5 = w_3_5 + (l_r*ouput_error*new_input3);	
	w_4_5 = w_4_5 + (l_r*ouput_error*new_input4);

	w_1_3 = w_1_3 + (l_r*ouput_error*x1);
	w_2_3 = w_2_3 + (l_r*ouput_error*x2);
	w_1_4 = w_1_4 + (l_r*ouput_error*x1);
	w_2_4 = w_2_4 + (l_r*ouput_error*x2);
	
	bias_5 = bias_5 + (l_r*ouput_error);
	bias_4 = bias_4 + (l_r*error_4);
	bias_3 = bias_3 + (l_r*error_3);
	
	printf("weight_1_3 :  %g\n\nweight_2_3 :  %g\n\n",w_1_3,w_2_3);
	printf("weight_1_4 :  %g\n\nweight_2_4 :  %g\n\n",w_1_4,w_2_4);
	printf("weight_3_5 :  %g\n\nweight_4_5 :  %g\n\n\n",w_3_5,w_4_5);
	
	printf("bias_3 :  %g\n\nbias_4 :  %g\n\nbias_5 :  %g\n\n\n",bias_3,bias_4,bias_5);
	
	//return calc(int x1, int x2, int label[], float l_r, float w_1_3, float w_1_4, float w_2_3, float w_2_4, float w_3_5, float w_4_5, float bias_3,float bias_4,float bias_5);
}

int main(){
	printf("\n\n-----------------------------------Training First Iteration----------------------------------\n\n\n");
	int x1=0, x2=0;
	int label[16] = {0,1,0,1,1,1,0,1,0,0,0,0,0,1,1,0};
	
	float l_r = 0.8;
	
	float w_1_3 = -0.2, w_1_4 = 0.4;
	float w_2_3 = -0.1, w_2_4 = 0.3;
	float w_3_5 = -0.3, w_4_5 = 0.1;	
	
	float bias[3] = {-0.1, 0.2, 0.3};
	
	calc(x1, x2, label[0], l_r, w_1_3, w_1_4, w_2_3, w_2_4, w_3_5, w_4_5, bias[0],bias[1],bias[2]);
	printf("\n\n-----------------------------------Training Second Iteration----------------------------------\n\n\n");
	
	int x3 = 0;
	int x4 = 1;
	
	w_1_3 = -0.2, w_1_4 = 0.4;
	w_2_3 = -0.1, w_2_4 = 0.3;
	w_3_5 = -0.352, w_4_5 = 0.04;
	
	bias[0] = -0.092;
	bias[1] = 0.197; 
	bias[2] = 0.191;
	
	calc(x3, x4, label[1], l_r, w_1_3, w_1_4, w_2_3, w_2_4, w_3_5, w_4_5, bias[0],bias[1],bias[2]);
	
	
	int x5 = 0;
	int x6 = 1;
	printf("Final : %g", sigmoid(input_update(w_1_3, w_2_3, bias[0], x5, x6)));
	
}

