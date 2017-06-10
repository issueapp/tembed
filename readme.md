# tembed

[Tom 7 embed](http://carnage-melon.tom7.org/embed/) as ruby C extension

## usage

```ruby
require 'tembed'

# override files
Tembed.call! '/path/to/font.ttf'
Tembed.call! File.new('/path/to/font.ttf')
Tembed.call! Pathname('/path/to/font.ttf')

# yield fixed data, but don't override file
Tembed.call('/path/to/font.ttf') do |data|
  # write fixed data
end
Tembed.call(IO.read('/path/to/font.ttf')) do |data|
  # write fixed data
end

```

## REPL

```sh
$ rake compile; irb -r ./lib/tembed
```

## resources

[ruby.h](https://github.com/ruby/ruby/blob/trunk/include/ruby/ruby.h)
[c api spec](https://github.com/ruby/spec/tree/master/optional/capi)

gem build tembed.gemspec
