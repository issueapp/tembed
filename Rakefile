require 'rake/extensiontask'

gemspec = Gem::Specification.load('tembed.gemspec')

Rake::ExtensionTask.new('tembed', gemspec) do |ext|
  ext.lib_dir = 'lib/native'
end
