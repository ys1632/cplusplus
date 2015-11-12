uniform float uVertexScale;
uniform float ratio;   

attribute vec2 aPosition;
attribute vec3 aColor;
attribute vec2 aTexCoord0, aTexCoord1;

varying vec3 vColor;
varying vec2 vTexCoord0, vTexCoord1;

void main() {
//according to the ratio of the width and height to adjust the drawing
if(ratio>=1)    //width>=height
  gl_Position = vec4(aPosition.x * uVertexScale /ratio, aPosition.y, 0,1);
 else  //width<height
  gl_Position = vec4(aPosition.x * uVertexScale , aPosition.y * ratio, 0,1);
  vColor = aColor;
  vTexCoord0 = aTexCoord0; //face
  vTexCoord1 = aTexCoord1; //squirrel
}
