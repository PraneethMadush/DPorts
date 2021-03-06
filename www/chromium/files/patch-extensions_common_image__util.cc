--- extensions/common/image_util.cc.orig	2019-01-30 02:18:01.000000000 +0100
+++ extensions/common/image_util.cc	2019-02-01 09:15:02.563494000 +0100
@@ -18,7 +18,11 @@
 #include "base/strings/stringprintf.h"
 #include "base/time/time.h"
 #include "base/timer/elapsed_timer.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkCanvas.h"
 #include "third_party/skia/include/core/SkColor.h"
