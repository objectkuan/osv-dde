# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "puck"
  s.version = "1.0.0.pre2"

  s.required_rubygems_version = Gem::Requirement.new("> 1.3.1") if s.respond_to? :required_rubygems_version=
  s.authors = ["Theo Hultberg"]
  s.date = "2013-07-20"
  s.description = "Puck takes your app and packs it along with all your gems and a complete JRuby runtime in a standalone Jar file that can be run with just `java -jar \u{2026}`"
  s.email = ["theo@iconara.net"]
  s.executables = ["puck"]
  s.files = ["bin/puck"]
  s.homepage = "http://github.com/iconara/puck"
  s.licenses = ["Apache License 2.0"]
  s.require_paths = ["lib"]
  s.rubyforge_project = "puck"
  s.rubygems_version = "1.8.24"
  s.summary = "Packs your JRuby app as a standalone Jar file"

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
