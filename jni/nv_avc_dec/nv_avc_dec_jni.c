#include "nv_avc_dec.h"

#include <stdlib.h>
#include <jni.h>

// This function must be called before
// any other decoding functions
JNIEXPORT jint JNICALL
Java_com_limelight_nvstream_av_video_AvcDecoder_init(JNIEnv *env, jobject this, jint width,
	jint height, jint perflvl)
{
	return nv_avc_init(width, height, perflvl);
}

// This function must be called after
// decoding is finished
JNIEXPORT void JNICALL
Java_com_limelight_nvstream_av_video_AvcDecoder_destroy(JNIEnv *env, jobject this) {
	nv_avc_destroy();
}

// This function redraws the surface
JNIEXPORT void JNICALL
Java_com_limelight_nvstream_av_video_AvcDecoder_redraw(JNIEnv *env, jobject this, jobject surface) {
	nv_avc_redraw(env, surface);
}

// packets must be decoded in order
// returns 0 on success, < 0 on error
JNIEXPORT jint JNICALL
Java_com_limelight_nvstream_av_video_AvcDecoder_decode(
	JNIEnv *env, jobject this, // JNI parameters
	jbyteArray indata, jint inoff, jint inlen)
{
	jint ret;
	jbyte* jni_input_data;

	jni_input_data = (*env)->GetByteArrayElements(env, indata, 0);

	ret = nv_avc_decode(&jni_input_data[inoff], inlen);

	// The input data isn't changed so it can be safely aborted
	(*env)->ReleaseByteArrayElements(env, indata, jni_input_data, JNI_ABORT);

	return ret;
}
