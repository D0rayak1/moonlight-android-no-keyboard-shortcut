package com.limelight.nvstream.av.video;

import android.view.Surface;

public class AvcDecoder {
	static {
		// FFMPEG dependencies
		System.loadLibrary("avutil-52");
		System.loadLibrary("swresample-0");
		System.loadLibrary("swscale-2");
		System.loadLibrary("avcodec-55");
		System.loadLibrary("avformat-55");
		System.loadLibrary("avfilter-3");
		
		System.loadLibrary("nv_avc_dec");
	}
	
	public static native int init(int width, int height, int perflvl);
	public static native void destroy();
	public static native void redraw(Surface surface);
	public static native int decode(byte[] indata, int inoff, int inlen);
}
