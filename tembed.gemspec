Gem::Specification.new do |s|
  s.name    = "tembed"
  s.version = "0.0.1"
  s.summary = "automatically set font.ttf file to least restrictive setting: installable embedding allowed"
  s.author  = "Khoa Nguyen"

  s.require_paths = ["lib"]

  s.files = Dir["ext/**/*.{c,rb}"] + Dir["lib/**/*.rb"]

  s.extensions = FileList["ext/**/extconf.rb"]

  s.add_development_dependency "rake-compiler"
end
