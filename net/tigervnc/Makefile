# $FreeBSD$

PORTNAME=	tigervnc
PORTVERSION=	1.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net x11-servers

MAINTAINER=	meta@FreeBSD.org
COMMENT=	High-performance, platform-neutral implementation of VNC

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

PATCH_DEPENDS=	${NONEXISTENT}:x11-servers/xorg-server:patch
BUILD_DEPENDS=	${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri \
		${LOCALBASE}/libdata/pkgconfig/fontutil.pc:x11-fonts/font-util \
		${LOCALBASE}/include/FL/Fl.H:x11-toolkits/fltk \
		bash:shells/bash
LIB_DEPENDS=	libxshmfence.so:x11/libxshmfence \
		libfontconfig.so:x11-fonts/fontconfig
# almost equivalent to x11-servers/xorg-server's
RUN_DEPENDS=	${LOCALBASE}/share/X11/xkb/rules/base:x11/xkeyboard-config \
		xkbcomp:x11/xkbcomp

USES=		autoreconf:build cmake:insource,noninja cpe gl iconv jpeg libtool \
		pkgconfig python ssl
USE_GL=		gl
USE_LDCONFIG=	yes
USE_GITHUB=	yes

CONFLICTS=	tightvnc-[0-9]*

GH_ACCOUNT=	TigerVNC

USE_XORG+=	ice pixman sm x11 xau xdamage xdmcp xext xfixes xfont xkbfile \
		xorg-macros xorgproto xrandr xrender xtrans xtst

CFLAGS+=	-fPIC

OPTIONS_DEFINE=		GNUTLS NLS PAM VIEWER DOCS
OPTIONS_DEFAULT=	GNUTLS PAM VIEWER
VIEWER_DESC=		Build vncviewer

.include <bsd.port.options.mk>

CMAKE_ARGS=	-G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${STAGE}${PREFIX}

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libtasn1.so:security/libtasn1 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgnutls.so:security/gnutls
CONFIGURE_ARGS+=	--enable-glx-tls
CMAKE_ARGS+=	-DENABLE_GNUTLS=1
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=0
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CMAKE_ARGS+=	-DENABLE_NLS=1
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=0
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CMAKE_ARGS+=	-DENABLE_PAM=1
.else
CMAKE_ARGS+=	-DENABLE_PAM=0
.endif

.if ${PORT_OPTIONS:MVIEWER}
CMAKE_ARGS+=	-DBUILD_VIEWER=1
LIB_DEPENDS+=	libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk
# ImageMagick is required to generate icons during build process
BUILD_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6
USE_XORG+=	xcursor xfixes xft xinerama
PLIST_SUB+=	VIEWER=""
INSTALLS_ICONS=	yes
DESKTOP_ENTRIES=	"TigerVNC viewer" "Connect to VNC server and display remote desktop" \
			"${PORTNAME}" "vncviewer" "Network;" false
.else
CMAKE_ARGS+=	-DBUILD_VIEWER=0
PLIST_SUB+=	VIEWER="@comment "
.endif

MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} --mandir=${PREFIX}/man/ \
		--docdir=${PREFIX}/share/doc/${PORTNAME}/ --with-pic --without-dtrace \
		--disable-static --disable-dri --disable-unit-tests \
		--disable-xinerama --disable-xvfb --disable-xnest --disable-xorg \
		--disable-dmx --disable-xwin --disable-xephyr --disable-kdrive \
		--disable-config-dbus --disable-config-hal \
		--disable-dri2 --enable-install-libxf86config --enable-glx \
		--with-default-font-path="catalogue:${LOCALBASE}/share/fonts,built-ins" \
		--with-xkb-path=${LOCALBASE}/share/X11/xkb \
		--with-xkb-bin-directory=${LOCALBASE}/bin \
		--with-serverconfig-path=${LOCALBASE}/lib/X11 \
		--disable-selective-werror \
		--disable-xwayland \
		--with-fontrootdir=${LOCALBASE}/share/fonts

.include <bsd.port.pre.mk>

# keep in sync with all platforms where libunwind is available
.if (${ARCH} == x86_64 || ${ARCH} == i386)
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

TIGERVNC_XORG_PATCH_VER=	${MAKE} -C "${PORTSDIR}/x11-servers/xorg-server" -V PORTVERSION:R:S,\.,,g

# import from x11-server/xorg-server/Makefile
.if ${SSL_DEFAULT} == base
# The reason why I use this is cause openssl from base doesn't
# install a .pc file and configure will fail trying to find it.
# Setting both of those variables to a *non-empty* value by-passes
# the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

XORG_WRKDIR=	${MAKE} -C ${PORTSDIR}/x11-servers/xorg-server -VWRKSRC

pre-patch:
	@${CP} -R `${XORG_WRKDIR}`/ ${WRKSRC}/unix/xserver/

post-patch:
	@cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver`${TIGERVNC_XORG_PATCH_VER}`.patch

post-configure:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${AUTORECONF} -fiv
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ./configure ${CONFIGURE_ARGS}

post-build:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} SHELL=${LOCALBASE}/bin/bash

post-install:
	@cd ${WRKSRC}/unix/xserver/hw/vnc/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/Xvnc ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/libvnc.so

.include <bsd.port.post.mk>
