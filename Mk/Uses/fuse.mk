# $FreeBSD: Mk/Uses/fuse.mk 330346 2013-10-14 19:42:48Z ohauer $
#
# handle dependency on the fuse port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	fuse
# Usage:	USES=fuse
# Valid ARGS:	does not require args
#
#
.if !defined(_INCLUDE_USES_FUSE_MK)
_INCLUDE_USES_FUSE_MK=	yes

.if defined(fuse_ARGS)
IGNORE=	USES=fuse does not require args
.endif

LIB_DEPENDS+=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs
.if !exists(/sbin/mount_fusefs) || ${OSVERSION} < 1000019
RUN_DEPENDS+=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
.endif

.endif
