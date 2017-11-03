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
      }
    }
    stage('chdir') {
      steps {
        dir(path: 'build') {
          sh 'printenv'
        }
        
      }
    }
  }
}