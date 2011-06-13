package com.hexgame.game;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLU;
import android.opengl.GLSurfaceView.Renderer;
import android.opengl.GLUtils;

public class OpenGLRenderer implements Renderer {

    static {
        System.loadLibrary("HexGame");
    }

	@Override
	public void onDrawFrame(GL10 gl) {
		OpenGLRenderer.draw();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		// Sets the current view port to the new size.
		gl.glViewport(0, 0, width, height);// OpenGL docs.
		// Select the projection matrix
		gl.glMatrixMode(GL10.GL_PROJECTION);// OpenGL docs.
		// Reset the projection matrix
		gl.glLoadIdentity();// OpenGL docs.
		// Calculate the aspect ratio of the window
		
		GLU.gluOrtho2D(gl, 0.0f, (float) width, height, 0.0f);
//		GLU.gluPerspective(gl, 45.0f,
//                                   (float) width / (float) height,
//                                   0.1f, 100.0f);
		// Select the modelview matrix
		gl.glMatrixMode(GL10.GL_MODELVIEW);// OpenGL docs.
		// Reset the modelview matrix
		gl.glLoadIdentity();// OpenGL docs.

		OpenGLRenderer.init();
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig eglConfig) {
		// Enable Smooth Shading, default not really needed.
		gl.glShadeModel(GL10.GL_SMOOTH);// OpenGL docs.
		// Depth buffer setup.
		gl.glClearDepthf(1.0f);// OpenGL docs.
		// Enables depth testing.
		gl.glEnable(GL10.GL_DEPTH_TEST);// OpenGL docs.
		// The type of depth testing to do.
		gl.glDepthFunc(GL10.GL_LEQUAL);// OpenGL docs.
		// Really nice perspective calculations.
		gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT, // OpenGL docs.
                          GL10.GL_FASTEST);

		gl.glTexEnvf(GL10.GL_TEXTURE_ENV, GL10.GL_TEXTURE_ENV_MODE, GL10.GL_MODULATE);

	    gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
	    gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);

		gl.glEnable(GL10.GL_BLEND);
		gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);

		gl.glEnable(GL10.GL_TEXTURE_2D);
		gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_LINEAR);
		gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
		
		OpenGLRenderer.addTexture("hextiles", loadTexture(gl, R.raw.texmap_hex), 2);
		OpenGLRenderer.addTexture("actions", loadTexture(gl, R.raw.actions), 4);
		OpenGLRenderer.addTexture("icons", loadTexture(gl, R.raw.icons), 4);
		OpenGLRenderer.addTexture("units", loadTexture(gl, R.raw.texmap), 2);		
	}
	
	private static int newTextureID(GL10 gl) {
	    int[] temp = new int[1];
	    gl.glGenTextures(1, temp, 0);
	    return temp[0];        
	}

	// Will load a texture out of a drawable resource file, and return an OpenGL texture ID:
	private int loadTexture(GL10 gl, int resource) {

	    // In which ID will we be storing this texture?
	    int id = newTextureID(gl);

	    // We need to flip the textures vertically:
//	    Matrix flip = new Matrix();
//	    flip.postScale(1f, -1f);

	    // This will tell the BitmapFactory to not scale based on the device's pixel density:
	    // (Thanks to Matthew Marshall for this bit)
	    BitmapFactory.Options opts = new BitmapFactory.Options();
	    opts.inScaled = false;

	    // Load up, and flip the texture:
	    Bitmap bmp = BitmapFactory.decodeResource(HexGame.context.getResources(), resource, opts);
//	    Bitmap bmp = Bitmap.createBitmap(temp, 0, 0, temp.getWidth(), temp.getHeight(), flip, true);
//	    temp.recycle();

	    gl.glBindTexture(GL10.GL_TEXTURE_2D, id);

	    // Set all of our texture parameters:
	    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_LINEAR);
	    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
//	    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_WRAP_S, GL10.GL_REPEAT);
//	    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_WRAP_T, GL10.GL_REPEAT);

	    // Generate, and load up all of the mipmaps:
        GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bmp, 0);

	    bmp.recycle();

	    return id;
	}
	
    public static native void init();
    public static native void draw();
    public static native void addTexture(String name, int textureId, int tiles);
}