int binarySearch(const vector<Object>& v, const Object& o) {
    int l = 0, r = v.size()-1;
    while (l+1 < r) {
        int mid = l+(r-l)/2;
        if (v[mid] == o) {
            // Do something;
        } else if (v[mid] < o) {
            // Do something;
        } else {
            // Do something;
        }
    }
    // Check v[l] and v[r]
    // to return the right one
    // or null
}
