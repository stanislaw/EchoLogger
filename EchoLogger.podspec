Pod::Spec.new do |s|
  s.name = 'EchoLogger'
  s.version = '0.0.10'
  s.license = { :type => 'MIT', :file => 'LICENSE' }
  s.summary = 'Fast and easy way to log things.'
  s.homepage = 'https://github.com/stanislaw/EchoLogger'
  s.author = { 'Stanislaw Pankevich' => 's.pankevich@gmail.com' }
  s.source = { :git => 'https://github.com/stanislaw/EchoLogger.git', :tag => s.version.to_s }

  s.source_files = 'EchoLogger/**/*.{h,m}'
  s.header_mappings_dir = 'EchoLogger'

  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.7'

  s.framework = 'Foundation'

  s.requires_arc = true

  s.dependency 'NSStringFromAnyObject'
end
