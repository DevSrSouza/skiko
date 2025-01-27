#include <jni.h>
#include "../interop.hh"
#include "interop.hh"
#include "SkSVGSVG.h"
#include "SkSVGRenderContext.h"

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetX
  (JNIEnv* env, jclass jclass, jlong ptr, jintArray jresult) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    auto x = instance->getX();
    jint result[2] = { rawBits(x.value()), (jint)x.unit() };
    env->SetIntArrayRegion(jresult, 0, 2, result);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetY
  (JNIEnv* env, jclass jclass, jlong ptr, jintArray jresult) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    auto y = instance->getY();
    jint result[2] = { rawBits(y.value()), (jint)y.unit() };
    env->SetIntArrayRegion(jresult, 0, 2, result);
}

extern "C" JNIEXPORT jobject JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetWidth
  (JNIEnv* env, jclass jclass, jlong ptr) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    return skija::svg::SVGLength::toJava(env, instance->getWidth());
}

extern "C" JNIEXPORT jobject JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetHeight
  (JNIEnv* env, jclass jclass, jlong ptr) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    return skija::svg::SVGLength::toJava(env, instance->getHeight());
}

extern "C" JNIEXPORT jobject JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetPreserveAspectRatio
  (JNIEnv* env, jclass jclass, jlong ptr) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    return skija::svg::SVGPreserveAspectRatio::toJava(env, instance->getPreserveAspectRatio());
}

extern "C" JNIEXPORT jobject JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetViewBox
  (JNIEnv* env, jclass jclass, jlong ptr) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    SkTLazy<SkSVGViewBoxType> viewBox = instance->getViewBox();
    return viewBox.isValid() ? skija::Rect::fromSkRect(env, *viewBox.get()) : nullptr;
}

extern "C" JNIEXPORT jobject JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nGetIntrinsicSize
  (JNIEnv* env, jclass jclass, jlong ptr, float width, float height, float dpi) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    SkSVGLengthContext lc({width, height}, dpi);
    SkSize size = instance->intrinsicSize(lc);
    return skija::Point::fromSkPoint(env, {size.width(), size.height()});
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nSetX
  (JNIEnv* env, jclass jclass, jlong ptr, float value, int unit) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    SkSVGLength lenght(value, static_cast<SkSVGLength::Unit>(unit));
    instance->setX(lenght);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nSetY
  (JNIEnv* env, jclass jclass, jlong ptr, float value, int unit) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    SkSVGLength lenght(value, static_cast<SkSVGLength::Unit>(unit));
    instance->setY(lenght);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nSetWidth
  (JNIEnv* env, jclass jclass, jlong ptr, float value, int unit) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    SkSVGLength lenght(value, static_cast<SkSVGLength::Unit>(unit));
    instance->setWidth(lenght);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nSetHeight
  (JNIEnv* env, jclass jclass, jlong ptr, float value, int unit) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    SkSVGLength lenght(value, static_cast<SkSVGLength::Unit>(unit));
    instance->setHeight(lenght);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nSetPreserveAspectRatio
  (JNIEnv* env, jclass jclass, jlong ptr, jint align, jint scale) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    instance->setPreserveAspectRatio(SkSVGPreserveAspectRatio { static_cast<SkSVGPreserveAspectRatio::Align>(align),
                                                                static_cast<SkSVGPreserveAspectRatio::Scale>(scale) });
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_svg_SVGSVGKt_SVGSVG_1nSetViewBox
  (JNIEnv* env, jclass jclass, jlong ptr, float l, float t, float r, float b) {
    SkSVGSVG* instance = reinterpret_cast<SkSVGSVG*>(static_cast<uintptr_t>(ptr));
    instance->setViewBox(SkRect::MakeLTRB(l, t, r, b));
}
