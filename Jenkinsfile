pipeline {
  agent {
    node {
      label 'builder'
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
        node(label: 'builder') {
          isUnix()
        }
        
      }
    }
  }
}