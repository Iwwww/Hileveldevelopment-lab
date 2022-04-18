cd src/
g++ main.cpp CMenu/CMenu.cpp CMenu/CMenuItem.cpp Models/User.cpp Models/Product.cpp Models/Employer/Employer.cpp Models/Provider/Provider.cpp -o ../a.out
chmod +x a.out
echo '<<< END COMPILATION >>>'
cd ..
./a.out