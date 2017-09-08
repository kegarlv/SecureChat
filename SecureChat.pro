QT += qml quick network widgets

CONFIG += c++14

SOURCES += src/messagelist.cpp \
    src/contactlist.cpp \
    src/messageworker.cpp \
    src/Backend.cpp \
    src/ContactInfo.cpp \
    src/CurrentUser.cpp \
    src/Dialog.cpp \
    src/main.cpp \
    src/Message.cpp \
    src/User.cpp \
    request.cpp \
    src/cipherhelper.cpp

HEADERS += src/Backend.h \
           src/ContactInfo.h \
           src/CurrentUser.h \
           src/Dialog.h \
           src/Message.h \
           src/User.h \
           libs/json.h \
    request.h \
    src/messagelist.h \
    src/contactlist.h \
    src/messageworker.h \
    libs/cryptopp/3way.h \
    libs/cryptopp/adler32.h \
    libs/cryptopp/aes.h \
    libs/cryptopp/algebra.h \
    libs/cryptopp/algparam.h \
    libs/cryptopp/arc4.h \
    libs/cryptopp/argnames.h \
    libs/cryptopp/aria.h \
    libs/cryptopp/asn.h \
    libs/cryptopp/authenc.h \
    libs/cryptopp/base32.h \
    libs/cryptopp/base64.h \
    libs/cryptopp/basecode.h \
    libs/cryptopp/bench.h \
    libs/cryptopp/blake2.h \
    libs/cryptopp/blowfish.h \
    libs/cryptopp/blumshub.h \
    libs/cryptopp/camellia.h \
    libs/cryptopp/cast.h \
    libs/cryptopp/cbcmac.h \
    libs/cryptopp/ccm.h \
    libs/cryptopp/chacha.h \
    libs/cryptopp/channels.h \
    libs/cryptopp/cmac.h \
    libs/cryptopp/config.h \
    libs/cryptopp/cpu.h \
    libs/cryptopp/crc.h \
    libs/cryptopp/cryptlib.h \
    libs/cryptopp/default.h \
    libs/cryptopp/des.h \
    libs/cryptopp/dh.h \
    libs/cryptopp/dh2.h \
    libs/cryptopp/dll.h \
    libs/cryptopp/dmac.h \
    libs/cryptopp/drbg.h \
    libs/cryptopp/dsa.h \
    libs/cryptopp/eax.h \
    libs/cryptopp/ec2n.h \
    libs/cryptopp/eccrypto.h \
    libs/cryptopp/ecp.h \
    libs/cryptopp/ecpoint.h \
    libs/cryptopp/elgamal.h \
    libs/cryptopp/emsa2.h \
    libs/cryptopp/eprecomp.h \
    libs/cryptopp/esign.h \
    libs/cryptopp/factory.h \
    libs/cryptopp/fhmqv.h \
    libs/cryptopp/files.h \
    libs/cryptopp/filters.h \
    libs/cryptopp/fips140.h \
    libs/cryptopp/fltrimpl.h \
    libs/cryptopp/gcm.h \
    libs/cryptopp/gf256.h \
    libs/cryptopp/gf2_32.h \
    libs/cryptopp/gf2n.h \
    libs/cryptopp/gfpcrypt.h \
    libs/cryptopp/gost.h \
    libs/cryptopp/gzip.h \
    libs/cryptopp/hex.h \
    libs/cryptopp/hkdf.h \
    libs/cryptopp/hmac.h \
    libs/cryptopp/hmqv.h \
    libs/cryptopp/hrtimer.h \
    libs/cryptopp/ida.h \
    libs/cryptopp/idea.h \
    libs/cryptopp/integer.h \
    libs/cryptopp/iterhash.h \
    libs/cryptopp/kalyna.h \
    libs/cryptopp/keccak.h \
    libs/cryptopp/lubyrack.h \
    libs/cryptopp/luc.h \
    libs/cryptopp/mars.h \
    libs/cryptopp/md2.h \
    libs/cryptopp/md4.h \
    libs/cryptopp/md5.h \
    libs/cryptopp/mdc.h \
    libs/cryptopp/mersenne.h \
    libs/cryptopp/misc.h \
    libs/cryptopp/modarith.h \
    libs/cryptopp/modes.h \
    libs/cryptopp/modexppc.h \
    libs/cryptopp/mqueue.h \
    libs/cryptopp/mqv.h \
    libs/cryptopp/nbtheory.h \
    libs/cryptopp/network.h \
    libs/cryptopp/nr.h \
    libs/cryptopp/oaep.h \
    libs/cryptopp/oids.h \
    libs/cryptopp/osrng.h \
    libs/cryptopp/ossig.h \
    libs/cryptopp/padlkrng.h \
    libs/cryptopp/panama.h \
    libs/cryptopp/pch.h \
    libs/cryptopp/pkcspad.h \
    libs/cryptopp/poly1305.h \
    libs/cryptopp/polynomi.h \
    libs/cryptopp/pssr.h \
    libs/cryptopp/pubkey.h \
    libs/cryptopp/pwdbased.h \
    libs/cryptopp/queue.h \
    libs/cryptopp/rabin.h \
    libs/cryptopp/randpool.h \
    libs/cryptopp/rc2.h \
    libs/cryptopp/rc5.h \
    libs/cryptopp/rc6.h \
    libs/cryptopp/rdrand.h \
    libs/cryptopp/resource.h \
    libs/cryptopp/rijndael.h \
    libs/cryptopp/ripemd.h \
    libs/cryptopp/rng.h \
    libs/cryptopp/rsa.h \
    libs/cryptopp/rw.h \
    libs/cryptopp/safer.h \
    libs/cryptopp/salsa.h \
    libs/cryptopp/seal.h \
    libs/cryptopp/secblock.h \
    libs/cryptopp/seckey.h \
    libs/cryptopp/seed.h \
    libs/cryptopp/serpent.h \
    libs/cryptopp/serpentp.h \
    libs/cryptopp/sha.h \
    libs/cryptopp/sha3.h \
    libs/cryptopp/shacal2.h \
    libs/cryptopp/shark.h \
    libs/cryptopp/simple.h \
    libs/cryptopp/siphash.h \
    libs/cryptopp/skipjack.h \
    libs/cryptopp/smartptr.h \
    libs/cryptopp/socketft.h \
    libs/cryptopp/sosemanuk.h \
    libs/cryptopp/square.h \
    libs/cryptopp/stdcpp.h \
    libs/cryptopp/strciphr.h \
    libs/cryptopp/tea.h \
    libs/cryptopp/threefish.h \
    libs/cryptopp/tiger.h \
    libs/cryptopp/trap.h \
    libs/cryptopp/trdlocal.h \
    libs/cryptopp/trunhash.h \
    libs/cryptopp/ttmac.h \
    libs/cryptopp/twofish.h \
    libs/cryptopp/validate.h \
    libs/cryptopp/vmac.h \
    libs/cryptopp/wait.h \
    libs/cryptopp/wake.h \
    libs/cryptopp/whrlpool.h \
    libs/cryptopp/winpipes.h \
    libs/cryptopp/words.h \
    libs/cryptopp/xtr.h \
    libs/cryptopp/xtrcrypt.h \
    libs/cryptopp/zdeflate.h \
    libs/cryptopp/zinflate.h \
    libs/cryptopp/zlib.h \
    libs/json.h \
    src/cipherhelper.h

RESOURCES += src/qml.qrc

LIBS += -lcryptopp
