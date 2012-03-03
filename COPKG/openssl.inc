@import "version.inc";
@import "outercurve.inc";

package {
    name: "openssl[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "OpenSSL";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

license[openssl] {
    license-url: "http://www.openssl.org/source/license.html";
    license-type: "openssl";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

requires {
    package: "zlib[${flavor}]-1.2.5.34-${Package.Architecture}-${Package.PublicKeyToken}";
}


metadata {
    summary: "openssl";
    description:  @"openssl"; 

    icon: @"openssl.png";
    
    author-version : "1.0.0f";
    bug-tracker: "https://github.com/coapp-packages/openssl/issues";
    stability : "0";
    licenses : {
        openssl
    };
}

compatability-policy {
    minimum: "1.0.0.0";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "1.0",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes,
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        openssl,
    };
    
    include : { 
        exes
    };
}

manifest[things-that-need-them2] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        zlib,
    };
    
    include : { 
        dlls
    };
}

assembly[openssl] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="OpenSSL",
        product-name="lua",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}