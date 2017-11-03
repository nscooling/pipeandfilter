pipeline {
  agent {
    docker {
      image 'ubuntu'
    }
    
  }
  stages {
    stage('build') {
      steps {
        echo 'simple pipeline'
      }
    }
    stage('step2') {
      steps {
        node(label: 'node') {
          isUnix()
        }
        
      }
    }
  }
}