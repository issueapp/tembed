case RUBY_PLATFORM
when /linux/
  require_relative './tembed.so'
when /darwin/
  require_relative './tembed.bundle'
end

module Tembed
  VERSION = '0.0.2'
end
