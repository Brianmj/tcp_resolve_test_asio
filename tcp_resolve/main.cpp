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
    
    net::ip::tcp::resolver resolver{ioc};   // create a resolver object that will be
    // used for the query
    
    // specify the host and how we're going to connect
    std::string host("www.apple.com"), service("https");
    
    std::error_code ec;
    
    // try to query the host. If success, then it'll return a range of endpoints 
    auto endpoints = resolver.resolve(host, service, ec);
    
    // if 0, then success
    if(!ec) {
        for(auto &endpoint : endpoints) {
            std::cout << endpoint.endpoint() << "\n";   // prints out apples ip address
            std::cout << endpoint.host_name() << "\n";  // prints out www.apple.com
            std::cout << endpoint.service_name() << "\n";   // used https, so it returns that
        }
    }
    return 0;
}
