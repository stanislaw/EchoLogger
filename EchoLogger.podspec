Pod::Spec.new do |s|
  s.name = 'EchoLogger'
  s.version = '0.0.3'
  s.license = { :type => 'MIT', :file => 'LICENSE' }
  s.summary = 'EchoLogger.'
  s.homepage = 'https://github.com/stanislaw/EchoLogger'
  s.author = { 'Stanislaw Pankevich' => 's.pankevich@gmail.com' }
  s.source = { :git => 'https://github.com/stanislaw/EchoLogger.git', :tag => s.version.to_s }
  # s.description = 'EchoLogger...'

  s.source_files = 'EchoLogger/**/*.{h,m}'
  s.header_mappings_dir = 'EchoLogger'

  s.framework = 'Foundation'

  s.weak_frameworks = 'UIKit', 'MapKit', 'CoreLocation'

  s.requires_arc = true
end
