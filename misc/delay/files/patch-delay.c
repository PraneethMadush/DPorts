
$FreeBSD: misc/delay/files/patch-delay.c 300896 2012-07-14 13:54:48Z beat $

--- delay.c.orig	Sun Aug 22 22:05:16 2004
+++ delay.c	Sun Aug 22 22:05:28 2004
@@ -21,6 +21,7 @@
 #include <sys/time.h>
 #include <unistd.h>
 #include <string.h>
+#include <stdlib.h>
 #include "parsetime.h"
 
 #ifdef HAVE_CURSES_H
