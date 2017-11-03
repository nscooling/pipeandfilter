pipeline {
  agent {
    docker {
      image 'rikorose/gcc-cmake'
    }
    
  }
  stages {
    stage('build') {
      steps {
        echo 'simple pipeline'
        dir(path: 'build')
      }
    }
  }
}