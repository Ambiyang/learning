## Note  
`The way to install openssl changes depending on the version of openssl and environment(os,vs etc..)`

## Download
- OpenSSL Source  
`git clone git://git.openssl.org/openssl.git`
- Strawberry Perl (Recommended downloads is ok)  
`http://strawberryperl.com/releases.html`  
`Note:it is necessary to run some scripts according to readme if you download the zip Perl (relocation.pl.bat and update_env.pl.bat)`
- NASM  
`https://www.nasm.us`
- Microsoft Visual Studio (my version is 2019 community) / (VC will also do?)

## Build
#### Open `Microsoft Visual Studio cmd(Developer command prompt for VS 2019)` change path to OpenSSL folder and execute the command below
- perl Configure VC-WIN32  
`the para VC-WIN32 depends on which version cmd is being used`
- nmake (It took me about 30-40 mins)
- nmake test (It took a long time)

## Install
- nmake install
