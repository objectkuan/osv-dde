# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "jruby-jars"
  s.version = "1.7.4"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Charles Oliver Nutter"]
  s.date = "2013-05-16"
  s.description = "This gem includes the core JRuby code and the JRuby 1.8/1.9 stdlib as jar files.\nIt provides a way to have other gems depend on JRuby without including (and\nfreezing to) a specific jruby-complete jar version."
  s.email = "headius@headius.com"
  s.homepage = "http://github.com/jruby/jruby/tree/master/gem/jruby-jars"
  s.require_paths = ["lib"]
  s.rubyforge_project = "jruby/jruby"
  s.rubygems_version = "1.8.24"
  s.summary = "The core JRuby code and the JRuby stdlib as jar files."

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
