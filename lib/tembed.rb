require_relative './native/tembed'

module Tembed
  def self.call thing
    require 'tempfile'
    f = Tempfile.new(['tembed', '.ttf'])

    if is_data = thing.respond_to?(:start_with?) && ! thing.start_with?('/')
      IO.write(f.path, thing, mode: 'w', encoding: thing.encoding)
    else
      require 'fileutils'
      FileUtils.cp(thing, f.path)
    end

    call! f

    yield f.read

    f.close
    f.unlink
  end
end
