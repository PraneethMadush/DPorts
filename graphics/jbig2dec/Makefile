# $FreeBSD$

PORTNAME=	jbig2dec
PORTVERSION=	0.15
CATEGORIES=	graphics devel
MASTER_SITES=	LOCAL/sunpoet:tests

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decoder implementation of the JBIG2 image compression format

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	PNG TESTS
OPTIONS_DEFAULT=PNG
TESTS_DESC=	Download and use test-images for post-build testing

CONFIGURE_ENV=	ac_cv_func_getopt_long=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf:build libtool
USES+=		ssl
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto
FILESDIR=	${.CURDIR}/does-not-exist

GH_ACCOUNT=	ArtifexSoftware
USE_GITHUB=	yes

SHEBANG_FILES=	test_jbig2dec.py
python_CMD=	${PYTHON_CMD}

PNG_CONFIGURE_OFF=	--without-libpng
PNG_CONFIGURE_ON=	--with-libpng=${LOCALBASE}
PNG_LIB_DEPENDS=	libpng.so:graphics/png
TESTS_DISTFILES=	jb2streams${EXTRACT_SUFX}:tests
TESTS_TEST_TARGET=	check-TESTS
TESTS_USES=		python:build shebangfix

pre-configure:
	@cd ${WRKSRC}/ && ${SH} autogen.sh

.include <bsd.port.mk>
