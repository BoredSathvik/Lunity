#include "Renderer.h"

#include "../../Utils/Utils.h"
#include "../../Client/Bridge/MinecraftUIRenderContext.h"
#include "../../Client/Bridge/ScreenContext.h"
#include "../../Client/Bridge/Tessellator.h"
#include "../../Client/Bridge/MeshHelpers.h"

ScreenContext* screenContext;
Tessellator* tessellator;
void Renderer::Setup(MinecraftUIRenderContext* renderContext) {
	screenContext = renderContext->screenContext;
	tessellator = screenContext->tessellator;
}

void Renderer::Begin() {
	vertCount = 0;
	vectors.clear();
}
void Renderer::End() {
	
	// 1: quads: four vertexs / a quadrilateral
	// 2: triangle list: https://docs.microsoft.com/en-us/windows/uwp/graphics-concepts/triangle-lists
	// 3: trianglestrip (6): https://docs.microsoft.com/en-us/windows/uwp/graphics-concepts/triangle-strips
	// 4: line list: https://docs.microsoft.com/en-us/windows/uwp/graphics-concepts/line-lists
	// 5: line strip (7): https://docs.microsoft.com/en-us/windows/uwp/graphics-concepts/line-strips
	
	tessellator->begin(3, vertCount);
	for(auto vec : vectors) {
		tessellator->vertex(vec.x, vec.y, 0);
	}
	MeshHelpers::renderMeshImmediately(screenContext, tessellator, Utils::GetUIMaterialPtr());
}

void Renderer::SetLineWidth(float width) {

}

void Renderer::SetColor(Vector3<float> color) {
	SetColor(color.x, color.y, color.z);
}
void Renderer::SetColor(float r, float g, float b) {
	SetColor(r, g, b, 1);
}
void Renderer::SetColor(Vector4<float> color) {
	SetColor(color.x, color.y, color.z, color.w);
}
void Renderer::SetColor(float r, float g, float b, float a) {
	screenContext->shaderColor->x = r;
	screenContext->shaderColor->y = g;
	screenContext->shaderColor->z = b;
	screenContext->shaderColor->w = a;
}

void Renderer::Vertex2D(float x, float y) {
	Vertex2D(Vector2<float>(x, y));
}
void Renderer::Vertex2D(Vector2<float> vector) {
	vertCount++;
	vectors.push_back(vector);
}