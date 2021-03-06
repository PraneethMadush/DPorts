# $FreeBSD$

PORTNAME=	puppetboard
PORTVERSION=	0.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	02

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Web interface to PuppetDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Consider switching to www/py-puppetboard03

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0.9.4:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.19:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb03>=0.2.0:databases/py-pypuppetdb03@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.2.1:www/py-requests@${PY_FLAVOR}

CONFLICTS_INSTALL=puppetboard-* puppetboard03-*
USE_GITHUB=	yes
GH_ACCOUNT=	voxpupuli

USES=		python:2.7
USE_PYTHON=	autoplist distutils

PLIST_FILES=	"@sample etc/puppetboard/default_settings.py.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppetboard
	${CP} ${WRKSRC}/puppetboard/default_settings.py ${STAGEDIR}${PREFIX}/etc/puppetboard/default_settings.py.sample

.include <bsd.port.mk>
