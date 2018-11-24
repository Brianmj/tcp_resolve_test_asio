//
//  main.cpp
//  tcp_resolve
//
//  Created by Brian Jones on 11/24/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//

#include <iostream>
#include <string>
#include <experimental/net>

namespace net = std::experimental::net;

int main(int argc, const char * argv[]) {
    // insert code here...
    net::io_context ioc;
    net::ip::tcp::resolver resolver{ioc};
    
    std::string host("www.apple.com"), service("https");
    
    std::error_code ec;
    
    auto ep = resolver.resolve(host, service, ec);
    
    if(!ec) {
        for(auto &endpoint : ep) {
            std::cout << endpoint.endpoint() << "\n";
            std::cout << endpoint.host_name() << "\n";
            std::cout << endpoint.service_name() << "\n";
        }
    }
    return 0;
}
