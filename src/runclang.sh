#!/bin/sh

clang --std=c++14 -stdlib=libstdc++ main.cpp CMenu/CMenu.cpp CMenu/CMenuItem.cpp Models/User.cpp Models/Product.cpp  Models/Employer/Employer.cpp Models/Provider/Provider.cpp  -g -o a.out -static -lstdc++ -lm -w && ./a.out
