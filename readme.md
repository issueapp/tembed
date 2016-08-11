# tembed

[Tom 7 embed](http://carnage-melon.tom7.org/embed/) as ruby C extension

## usage

```ruby
require 'tembed'

Tembed.call '/path/to/font.ttf'

# unsupported
Tembed.call Pathname.new('/path/to/font.ttf')
Tembed.call '/path/to/font1.ttf', Pathname.new('/path/to/font2.ttf')
Tembed.call ['/path/to/font1.ttf', Pathname.new('/path/to/font2.ttf')]
```
