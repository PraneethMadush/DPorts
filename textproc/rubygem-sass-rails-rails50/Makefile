# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	5.0.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties50>=5.0.0:www/rubygem-railties50 \
		rubygem-sass>=3.1:textproc/rubygem-sass \
		rubygem-sprockets3>=3.0.3:devel/rubygem-sprockets3 \
		rubygem-sprockets-rails-rails50>=2.0:devel/rubygem-sprockets-rails-rails50 \
		rubygem-tilt>=1.1:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
