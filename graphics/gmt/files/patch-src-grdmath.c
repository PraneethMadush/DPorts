--- src/grdmath.c.orig	2016-03-07 01:35:42 UTC
+++ src/grdmath.c
@@ -51,11 +51,7 @@
  */
 
 /* Circumvent Solaris problem. See bug #817 */
-#ifdef __FreeBSD__
-#define _XOPEN_SOURCE
-#else
 #define _XOPEN_SOURCE 600
-#endif
 
 #include "gmt.h"
 
