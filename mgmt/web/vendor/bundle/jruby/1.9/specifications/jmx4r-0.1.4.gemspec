# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "jmx4r"
  s.version = "0.1.4"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Jeff Mesnil"]
  s.date = "2012-10-23"
  s.description = "jmx4r is a JMX library for JRuby\n"
  s.email = "jmesnil@gmail.com"
  s.extra_rdoc_files = ["README.rdoc", "LICENSE.txt"]
  s.files = ["README.rdoc", "LICENSE.txt"]
  s.homepage = "http://jmesnil.net/wiki/Jmx4r"
  s.rdoc_options = ["--title", "jmx4r Documentation", "--main", "README.rdoc"]
  s.require_paths = ["lib"]
  s.rubyforge_project = "jmx4r"
  s.rubygems_version = "1.8.24"
  s.summary = "jmx4r is a JMX library for JRuby"

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
