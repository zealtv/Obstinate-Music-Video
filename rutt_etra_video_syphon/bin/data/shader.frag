#version 120

uniform sampler2D tex0;

varying float depth;
varying vec4 colorVarying;
varying vec2 texCoordVarying;





void main(){
    //work around to prevent unused variables breaking the shader
    vec4 pixelIn = texture2D(tex0, texCoordVarying);
	vec4 c0 = pixelIn;

	//Do stuff here
	//...



	//just an indicator to show the effect is on
	//delete if creating your own effect
	if( texCoordVarying.x > 0.9 && texCoordVarying.y < 0.1 )
	{
		c0 = vec4( 1.0, 0.0, 0.0, 1.0 );
	}




	gl_FragColor = c0;
}
