#include "core.h"

#ifdef SH_FRAGMENT_SHADER

    SH_BEGIN_PROGRAM
        shInput(float2, UV)
        shSampler2D(SceneBuffer)
    SH_START_PROGRAM
    {
        shOutputColour(0) = shSample(SceneBuffer, UV);
    }

#endif
