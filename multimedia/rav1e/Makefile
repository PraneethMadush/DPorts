# $FreeBSD$

PORTNAME=	rav1e
PORTVERSION=	s20190225
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast and safe AV1 encoder

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_x86_64=	nasm:devel/nasm

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	xiph
GH_TAGNAME=	7fd3938
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	aho-corasick-0.6.10 \
		ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.14 \
		backtrace-sys-0.1.28 \
		bindgen-0.47.3 \
		bitflags-1.0.4 \
		bitstream-io-0.8.2 \
		byteorder-1.3.1 \
		cast-0.2.2 \
		cc-1.0.29 \
		cexpr-0.3.4 \
		cfg-if-0.1.6 \
		clang-sys-0.26.4 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		cmake-0.1.35 \
		criterion-0.2.10 \
		criterion-plot-0.3.0 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		csv-1.0.5 \
		csv-core-0.1.5 \
		dav1d-sys-0.1.2 \
		difference-2.0.0 \
		either-1.5.1 \
		env_logger-0.6.0 \
		error-chain-0.10.0 \
		failure-0.1.5 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		hashbrown-0.1.8 \
		humantime-1.2.0 \
		itertools-0.8.0 \
		itoa-0.4.3 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		libloading-0.5.0 \
		log-0.4.6 \
		memchr-2.2.0 \
		memoffset-0.2.1 \
		metadeps-1.1.2 \
		nasm-rs-0.1.4 \
		nodrop-0.1.13 \
		nom-4.2.0 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		paste-0.1.4 \
		paste-impl-0.1.4 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.14 \
		pretty_assertions-0.5.1 \
		proc-macro-hack-0.5.4 \
		proc-macro2-0.4.27 \
		quick-error-1.2.2 \
		quote-0.6.11 \
		rand-0.5.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_os-0.1.2 \
		rand_xoshiro-0.1.0 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-1.1.0 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.5 \
		rustc-demangle-0.1.13 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		scan_fmt-0.1.3 \
		scopeguard-0.3.3 \
		serde-1.0.88 \
		serde_derive-1.0.88 \
		serde_json-1.0.38 \
		strsim-0.7.0 \
		syn-0.15.26 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		tinytemplate-1.0.1 \
		toml-0.2.1 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.7 \
		which-2.0.1 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		y4m-0.3.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
