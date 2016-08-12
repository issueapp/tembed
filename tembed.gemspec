require File.join(File.expand_path("../lib", __FILE__), 'tembed')

Gem::Specification.new do |s|
  s.name    = "tembed"
  s.version = Tembed::VERSION
  s.summary = "automatically set font.ttf file to least restrictive setting: installable embedding allowed"
  s.author  = "Khoa Nguyen"

  s.require_paths = ["lib"]

  s.files = Dir["ext/**/*.{c,rb}"] + Dir["lib/**/*.rb"]

  s.extensions = Dir["ext/**/extconf.rb"]

  s.add_development_dependency "rake-compiler"
end
