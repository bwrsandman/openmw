#include "core.h"

// Vertex Shader
#ifdef SH_VERTEX_SHADER
    SH_BEGIN_PROGRAM
        shInput(float2, UV)

    SH_START_PROGRAM
    {
        shOutputPosition = shInputPosition;
    }


// Fragment Shader
#else

    SH_BEGIN_PROGRAM
        shInput(float2, UV)
        shSampler2D(SceneBuffer)
    SH_START_PROGRAM
    {
        float2 vr_distortion_red_uv = 1.0 - UV;
        float2 vr_distortion_green_uv = UV;
        float2 vr_distortion_blue_uv = UV;
        shOutputColour(0) = float4(
            shSample(SceneBuffer, vr_distortion_red_uv).r,
            shSample(SceneBuffer, vr_distortion_green_uv).g,
            shSample(SceneBuffer, vr_distortion_blue_uv).b,
            0.0
        );
    }

#endif
