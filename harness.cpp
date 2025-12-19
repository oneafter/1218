#include <mapnik/map.hpp>
#include <mapnik/load_map.hpp>
#include <mapnik/datasource_cache.hpp>
#include <cstdint>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    static bool initialized = false;
    if (!initialized) {
        // init Mapnik
        mapnik::datasource_cache::instance();
        initialized = true;
    }

    if (Size == 0) return 0;

    try {
        std::string xml_string((const char*)Data, Size);
        mapnik::Map m(256, 256);
        
        // strict=false
        mapnik::load_map_string(m, xml_string, false, "/tmp"); 
        
    } catch (...) {
        
    }
    return 0;
}
