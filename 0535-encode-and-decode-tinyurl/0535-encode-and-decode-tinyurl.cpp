class Solution {
public:
    unordered_map<string, string> encode_mp;
    unordered_map<string, string> decode_mp;
    string base = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encode_mp.find(longUrl) == encode_mp.end()) {
            string encoded_str = to_string(encode_mp.size() + 1);
            string url = base + encoded_str;
            encode_mp[longUrl] = url;
            decode_mp[url] = longUrl;
        }

        return encode_mp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decode_mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));