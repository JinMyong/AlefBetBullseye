/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.bullseye.alefbet;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Toast;

public class AlefBetBullseye extends Cocos2dxActivity{
	private static Cocos2dxActivity me = null;
    protected void onCreate(Bundle savedInstanceState){
    	me = this;
		super.onCreate(savedInstanceState);	
	}

    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// AlefBetBullseye should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }
    
    public static void openWebsite(String url) { 
        Intent i = new Intent(Intent.ACTION_VIEW);  
        i.setData(Uri.parse(url));
        me.startActivity(i);
    }
    
    public static void sendemail(String mailbody)
    {
    	Intent shareIntent = new Intent(android.content.Intent.ACTION_SEND);
		shareIntent.setType("text/plain");
		shareIntent.putExtra(android.content.Intent.EXTRA_EMAIL, "");
		shareIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, ""); // subject
		shareIntent.putExtra(android.content.Intent.EXTRA_TEXT, mailbody); // Text
		  
		try
        {
			getContext().startActivity(Intent.createChooser(shareIntent, "Send email..."));
        }
        catch (android.content.ActivityNotFoundException ex)
        {
            Toast.makeText(me, "There are no email clients installed.", Toast.LENGTH_SHORT);
        }
    }
    
    public static void sendemailWithScreenShot(String filelocation, String mailbody)
    {
    	
		Bitmap bmp = BitmapFactory.decodeFile(filelocation);

		File imagefile = new File(me.getExternalCacheDir().getAbsolutePath(), "screenshot.png");
		if (imagefile.exists())
		{
			imagefile.delete();
		}
		if (imagefile != null){
			FileOutputStream out = null;
	        try {
	            out = new FileOutputStream(imagefile);
	            bmp.compress(Bitmap.CompressFormat.PNG, 100, out);
	            out.flush();
	        } catch (Exception e) {
	            e.printStackTrace();
	        } finally {
	            try {
	                if (out != null) out.close();
	            }
	            catch (IOException ignore) {}
	        }
		}
		
		Intent shareIntent = new Intent(android.content.Intent.ACTION_SEND);
		shareIntent.setType("text/plain");
		shareIntent.putExtra(android.content.Intent.EXTRA_EMAIL, "");
		shareIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, ""); // subject
		shareIntent.putExtra(android.content.Intent.EXTRA_TEXT, mailbody); // Text
		shareIntent.setType("image/png");
		shareIntent.putExtra(android.content.Intent.EXTRA_STREAM, Uri.fromFile(imagefile));
		
		try
        {
			getContext().startActivity(Intent.createChooser(shareIntent, "Send email..."));
        }
        catch (android.content.ActivityNotFoundException ex)
        {
            Toast.makeText(me, "There are no email clients installed.", Toast.LENGTH_SHORT);
        }
    }
    
    static {
        System.loadLibrary("cocos2dcpp");
    }     
}
