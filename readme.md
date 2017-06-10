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

/usr/local/lib/ry/rubies/2.3.0/include/ruby-2.3.0/ruby/ruby.h

gem build tembed.gemspec
