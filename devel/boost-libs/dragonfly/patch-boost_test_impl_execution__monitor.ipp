DragonFly has no sigqueue(2) implementation

--- boost/test/impl/execution_monitor.ipp.orig	2018-04-11 13:49:08 UTC
+++ boost/test/impl/execution_monitor.ipp
@@ -378,10 +378,12 @@ system_signal_exception::report() const
                       (int)m_sig_info->si_uid, (int)m_sig_info->si_pid );
         break;
 #endif            
+#ifndef __DragonFly__
     case SI_QUEUE:
         report_error( execution_exception::system_error,
                       "signal: sent by sigqueue()" );
         break;
+#endif
     case SI_TIMER:
         report_error( execution_exception::system_error,
                       "signal: the expiration of a timer set by timer_settimer()" );
