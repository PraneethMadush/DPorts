# $FreeBSD$

PORTNAME=	bitlbee-mastodon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	irc

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Bitlbee plugin to communicate with Mastodon instances

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bitlbee>=3.5:irc/bitlbee
RUN_DEPENDS=	bitlbee>=3.5:irc/bitlbee

USES=		autoreconf gnome libtool pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	kensanata

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plugindir=${PREFIX}/lib/bitlbee

PLIST_FILES=	lib/bitlbee/mastodon.so \
		share/bitlbee/mastodon-help.txt

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
