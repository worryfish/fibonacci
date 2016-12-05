INSTALLATION OF FIBONACCI EXTENSION
==================================

MANUAL INSTALLATION
-------------------

Checkout the project or download it as archive. In the package directory run: 

    $ phpize 
    $ ./configure --enable-fibonacci
    $ make 

Do install with root priveleges:

    # make install

In php.ini, or some other configuration like
</etc/php/7.1/mods-available/fibonacci.ini> write:

    extension=fibonacci.so

and activate this ini-file accirding your distro/

FINALLY
------

Restart the SAPI server(Apache, PHP-FPM etc.), if any.
