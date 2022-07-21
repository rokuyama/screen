# GNU screen with MacIM support
- MacIM can be controlled by [escape sequences compatible to TeraTerm](https://ttssh2.osdn.jp/manual/4/ja/about/ctrlseq.html)
- [NFD patch](https://gist.github.com/mrkn/626040/c1abe69d692f6c1dcf0bebbdfb8b96dbd3728d46) is applied
- Add `--enable-nosuid` configure option to install without suid by dropping some features

## requirements
- [im-select](https://github.com/daipeihust/im-select)
- [autoconf](https://www.gnu.org/software/autoconf/)

## build
```
git clone https://github.com/rokuyama/screen.git
cd screen/src
./autogen.sh
./configure --prefix=/usr/local --enable-nosuid --enable-macim
make
sudo make install
```

## usage

You need to set `imasciikey` and `imlocalkey` appropriately, which can be obtained by `im-select` command. Your `~/.screenrc` should be, e.g.:
```
imasciikey com.justsystems.inputmethod.atok30.Roman
imlocalkey com.justsystems.inputmethod.atok30.Japanese
macim on
```
Then, you can control MacIM via escape sequences from terminal-based applications.
