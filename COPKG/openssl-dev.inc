@import "version.inc" ;
@import "outercurve.inc" ;

package {
    name: "openssl-dev[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";

    display-name: "OpenSSL developer library";
}

metadata {
    summary: "The OpenSSL developer library";
    description: @"OpenSSL"; 

    icon: @"openssl.png";
    
    author-version : "1.0.0f";
    bug-tracker: "https://github.com/coapp-packages/openssl/issues";
    stability : "0";
    licenses : {
        openssl
    };
}

requires {
    package: "openssl-dev-common-${package-version}-any-${Package.PublicKeyToken}";
    package: "openssl[${flavor}]-${package-version}-${Package.Architecture}-${Package.PublicKeyToken}";
	package: "zlib-dev-common-1.2.5.34-any-${Package.PublicKeyToken}";
    package: "zlib[${flavor}]-1.2.5.34-${Package.Architecture}-${Package.PublicKeyToken}";
}

developer-library[openssl] {
    libraries : {
        libs
    };
}