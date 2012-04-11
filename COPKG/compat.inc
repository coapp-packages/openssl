compatability-policy {
    minimum: "1.0.0.0";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "1.0",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}
